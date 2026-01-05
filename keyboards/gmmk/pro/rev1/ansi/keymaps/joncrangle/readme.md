# GMMK Pro Keymap

A GMMK Pro layout with custom tap dances, autocorrect, and RGB features.

## Attribution

This keymap is based on work by [gourdo1](https://github.com/gourdo1/qmk_firmware/tree/PR-branch-2023-Q2) and [Jonavin](https://github.com/qmk/qmk_firmware/tree/master/keyboards/gmmk/pro/rev1/ansi/keymaps/jonavin).

### Inherited from gourdo1/Jonavin

- Layer structure (`_BASE`, `_FN1`, `_NUMPADMOUSE`, `_MOUSEKEY`, `_GAME`, `_COLEMAK`)
- Autocorrect engine and dictionary
- RGB Matrix indicators (CapsLock, NumLock, ScrollLock, layer-specific lighting)
- RGB nightmode and idle timeout
- Encoder functionality (volume, layers, page navigation, word navigation, RGB control, media)
- User config toggles (FN+1-9) with EEPROM persistence
- Custom keycodes (`ENCFUNC`, `CAPSNUM`, `LEFTOFENC`, `BELOWENC`, email macros)
- Double-tap behaviors (ESC to base layer, Shift for CapsLock)
- Caps Word with custom continuity characters
- Paddle game (`GAME_ENABLE`)
- Windows key lock

### Customizations by joncrangle

- **Tap Dance: Super Caps** - Replaces CapsLock with multi-function key (Tap=Esc, Double=Toggle Numpad, Hold=Momentary Numpad)
- **Tap Dance: Productivity** - Right Ctrl key (Tap=Copy, Double=Paste, Hold=Cut) - Cross-platform (Ctrl/Cmd)
- **Tap Dance: Encoder** - Encoder button (Tap=Mute, Double=Play/Pause)
- Namespace renamed from `gourdo1` to `joncrangle`
- Updated deprecated QMK options (`RGB_MATRIX_SLEEP`, `NKRO_ENABLE`)

## Layers

| Layer | Name | Description |
|-------|------|-------------|
| 0 | `_BASE` | Default QWERTY layout |
| 1 | `_FN1` | Function layer (media, RGB, settings) |
| 2 | `_NUMPADMOUSE` | Overlay numpad + mouse keys |
| 3 | `_MOUSEKEY` | Dedicated mouse key layer |
| 4 | `_GAME` | Gaming mode (optional, requires `GAME_ENABLE=yes`) |
| 5 | `_COLEMAK` | Colemak layout (optional, requires `COLEMAK_LAYER_ENABLE=yes`) |

## Keymap Details

### Layer 0: Base Layer (`_BASE`)

| Key | Action | Key | Action |
|-----|--------|-----|--------|
| `CapsLock` | Tap = `Esc`, Double Tap = Toggle Numpad Layer, Hold = Numpad | `Knob Click` | Tap = Mute, Double Tap = Play/Pause |
| `Shift` | Double Tap = CapsLock | `Home` | Can be swapped with `FN+4` |
| `RCtrl` | Tap = Copy (Ctrl/Cmd+C), Double Tap = Paste (Ctrl/Cmd+V), Hold = Cut (Ctrl/Cmd+X) | | |

### Layer 1: Function Layer (`_FN1`)

| Key | Action | Key | Action |
|-----|--------|-----|--------|
| `Esc` | Clear EEPROM | `F1` | My Computer |
| `F2` | Browser | `F3` | Calculator |
| `F4` | Media Player | `F5` | Media Previous Track |
| `F6` | Media Next Track | `F7` | Media Play|
| `F8` | Media Stop | `F9` | Volume Down |
| `F10` | Volume Up | `F11` | Print Screen |
| `F12` | Scroll Lock | `Home` | Pause Break |
| `[` / `]` | Snap Window Left / Right | `\` | Bootloader |
| `Y` / `O` | `yahoo.com` / `outlook.com` | `G` / `H` | `gmail.com` / `hotmail.com` |
| `P` | Paddle Game | `L` | Lock PC (Win+L) |
| `Z` | RGB Night Mode | `B` | Bootloader |
| `N` | Num Lock | `.` / `/` | `.com` / Ctrl+Alt+Del |
| `Up` / `Down` | RGB Mode Up / Down | `Left` / `Right` | RGB Speed - / + |
| `Delete` | RGB Toggle | `Page Up` / `Page Down` | Home / End |

#### Quick Settings

Hold FN + number key to toggle:
1. CapsLock RGB highlight
2. Numpad RGB highlight
3. Double-tap ESC to base layer
4. Swap DEL/HOME positions
5. Double-tap Shift for CapsLock
6. Encoder button function
7. Insert on Shift+Backspace
8. Disable modded-Space
9. AutoCorrect

### Layer 2: Numpad & Mouse (`_NUMPADMOUSE`)

| Key | Action | Key | Action |
|-----|--------|-----|--------|
| `1` - `0` | Numpad `1` - `0` | `-` / `=` | Numpad `-` / `+` |
| `Q` / `W` / `E` | Page Up / Up Arrow / Page Down | `U` / `I` / `O` | Numpad `4` / `5` / `6` |
| `A` / `S` / `D` | Left / Down / Right Arrow | `J` / `K` / `L` | Numpad `1` / `2` / `3` |
| `P` | Numpad `+` | `;` | Numpad `*` |
| `M` / `,` | Numpad `0` / `00` | `.` / `/` | Numpad `.` / `/` |
| `Enter` | Numpad Enter | `Space` | Numpad Enter |
| `RShift` | Mouse Left Click | `RCtrl` | Mouse Middle Click |
| `Up` / `Down` | Mouse Up / Down | `Left` / `Right` | Mouse Left / Right |
| `Page Up` | Mouse Scroll Up | `Page Down` | Mouse Scroll Down |
| `End` | Mouse Right Click | | |

## Encoder Functions

- **Default**: Volume up/down
- **Left Shift + turn**: Change layers
- **Right Shift + turn**: Page up/down
- **Left Ctrl + turn**: Navigate words
- **Right Alt + turn**: RGB hue
- **Left Alt + turn**: Media track next/prev
- **FN layer**: RGB timeout adjustment
- **FN layer**: click = system sleep

## Building

```bash
just build    # Compile firmware
just flash    # Compile and flash
just dev      # Generate clangd config
just lint     # Check for errors
```
