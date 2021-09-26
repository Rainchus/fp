PACKAGE    ?= $(NAME)
URL        ?= github.com/jcog/fp
CC          = mips64-gcc
LD          = mips64-g++
AS          = mips64-gcc
OBJCOPY     = mips64-objcopy
ARMIPS      = armips
GRU         = gru
GRC         = grc
RESDESC     = $(RESDIR)/resources.json
LUAFILE     = crc.lua
SRCDIR      = src
OBJDIR      = obj
BINDIR      = bin
LIBDIR      = lib
RESDIR      = res
CFILES      = *.c
SFILES      = *.s
FP_VERSIONS = PM64J PM64U
NAME        = fp
NDEBUG     ?= 0

ADDRESS     = 0x80400040
CFLAGS      = -c -MMD -MP -std=gnu11 -Wall -ffunction-sections -fdata-sections -O1 -fno-reorder-blocks 
CPPFLAGS    = -DPACKAGE=$(PACKAGE) -DURL=$(URL) -DF3DEX_GBI_2
LDFLAGS     = -T gl-n64.ld -L$(LIBDIR) -nostartfiles -specs=nosys.specs -Wl,--gc-sections -Wl,--defsym,start=$(ADDRESS) 
ALL_LIBS    = $(LIBS)

ifeq ($(NDEBUG),1)
  CFLAGS += -DNDEBUG
  CPPFLAGS += -DNDEBUG
endif

FP          = $(foreach v,$(FP_VERSIONS),patch-fp-$(v))
FP-PM64U    = patch-fp-PM64U
FP-PM64J    = patch-fp-PM64J

all         : $(FP)
us          : $(FP-PM64U)
jp          : $(FP-PM64J)
clean       :
	rm -rf $(OBJDIR) $(BINDIR)
crc         :
	@find ./rom/ -name "fp-*.z64" -type f -printf "$(GRU) $(LUAFILE) %f\n" -exec $(GRU) $(LUAFILE) {} \;

.PHONY: clean all crc us jp

define bin_template
SRCDIR-$(1)      = src
RESDIR-$(1)      = res/$(3)
OBJDIR-$(1)      = obj/$(2)
BINDIR-$(1)      = bin/$(2)
NAME-$(1)        = $(1)
BUILDFILE-$(1)   = build.$(2).asm
CPPFLAGS-$(1)    = -DPM64_VERSION=$(2) $(CPPFLAGS)
CSRC-$(1)       := $$(foreach s,$$(CFILES),$$(wildcard $$(SRCDIR-$(1))/$$(s)))
COBJ-$(1)        = $$(patsubst $$(SRCDIR-$(1))/%,$$(OBJDIR-$(1))/%.o,$$(CSRC-$(1)))
SSRC-$(1)       := $$(foreach s,$$(SFILES),$$(wildcard $$(SRCDIR-$(1))/$$(s)))
SOBJ-$(1)        = $$(patsubst $$(SRCDIR-$(1))/%,$$(OBJDIR-$(1))/%.o,$$(SSRC-$(1)))
RESSRC-$(1)     := $$(wildcard $$(RESDIR-$(1))/*)
RESOBJ-$(1)      = $$(patsubst $$(RESDIR-$(1))/%,$$(OBJDIR-$(1))/$$(RESDIR)/%.o,$$(RESSRC-$(1)))
ELF-$(1)         = $$(BINDIR-$(1))/$(3).elf
BIN-$(1)         = $$(BINDIR-$(1))/$(3).bin
OUTDIR-$(1)      = $$(OBJDIR-$(1)) $$(OBJDIR-$(1))/$$(RESDIR) $$(BINDIR-$(1))
BUILD-$(1)       = $(1)
CLEAN-$(1)       = clean-$(1)
$$(BUILD-$(1))   : $$(BIN-$(1))
$$(CLEAN-$(1))   :rm -rf $$(OUTDIR-$(1))

$$(COBJ-$(1))     : $$(OBJDIR-$(1))/%.o: $$(SRCDIR-$(1))/% | $$(OBJDIR-$(1))
	$(CC) $$(CPPFLAGS-$(1)) $$(CFLAGS) $$< -o $$@
$$(SOBJ-$(1))     : $$(OBJDIR-$(1))/%.o: $$(SRCDIR-$(1))/% | $$(OBJDIR-$(1))
	$(AS) -c -MMD -MP $$< -o $$@
$$(ELF-$(1))      : $$(COBJ-$(1)) $$(SOBJ-$(1)) $$(RESOBJ-$(1)) | $$(BINDIR-$(1))
	$(LD) $$(LDFLAGS) $$^ $$(ALL_LIBS) -o $$@
$$(BIN-$(1))      : $$(ELF-$(1)) | $$(BINDIR-$(1))
	$(OBJCOPY) -S -O binary $$< $$@
$$(RESOBJ-$(1))   : $$(OBJDIR-$(1))/$$(RESDIR)/%.o: $$(RESDIR-$(1))/% $$(RESDESC) | $$(OBJDIR-$(1))/$$(RESDIR)
	$$(GRC) $$< -d $$(RESDESC) -o $$@
$$(OUTDIR-$(1))   : 
	mkdir -p $$@
patch-$(1)        : $$(BIN-$(1))
	$(ARMIPS) $$(BUILDFILE-$(1))
	@find ./rom/ -name "fp-*.z64" -type f -printf "$(GRU) $(LUAFILE) %f\n" -exec $(GRU) $(LUAFILE) {} \;
endef

$(foreach v,$(FP_VERSIONS),$(eval $(call bin_template,fp-$(v),$(v),fp)))

$(FP-PM64U)	:	LDFLAGS	+=	-Wl,-Map=bin/PM64U/fp-u.map
$(FP-PM64J)	:	LDFLAGS	+=	-Wl,-Map=bin/PM64J/fp-j.map

$(FP-PM64U)	:	LIBS	:=	-lpm-us
$(FP-PM64J)	:	LIBS	:=	-lpm-jp


