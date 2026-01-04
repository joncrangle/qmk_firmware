keyboard := "gmmk/pro/rev1/ansi"
keymap   := "joncrangle"

default:
    just --list

# Compile the firmware
build:
    qmk compile -kb {{keyboard}} -km {{keymap}}

# Compile and attempt to flash (Put keyboard in DFU mode first!)
flash:
    qmk flash -kb {{keyboard}} -km {{keymap}}

# Check the keymap for common errors
lint:
    qmk lint -kb {{keyboard}} -km {{keymap}}

# Clean up build artifacts
clean:
    qmk clean

# Sync fork with the official QMK repo (upstream)
sync:
    git checkout master
    git fetch upstream
    git merge upstream/master
    git push origin master
    qmk git-submodule

# Add upstream remote (run once after cloning your fork)
setup-upstream:
    git remote add upstream https://github.com/qmk/qmk_firmware.git

# Check QMK environment is configured correctly
doctor:
    qmk doctor

# Show keyboard info
info:
    qmk info -kb {{keyboard}} -km {{keymap}}

# Generate clangd configuration (Fixes missing imports)
dev:
    qmk compile -kb {{keyboard}} -km {{keymap}} --compiledb
