# GMMK Pro Keymap

A GMMK Pro layout with custom tap dances, autocorrect, and RGB features.

## Attribution

This keymap is based on work by [gourdo1](https://github.com/gourdo1/qmk_firmware/tree/PR-branch-2023-Q2) and [Jonavin](https://github.com/qmk/qmk_firmware/tree/master/keyboards/gmmk/pro/rev1/ansi/keymaps/jonavin), licensed under GPL-2.0.

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

## Tap Dances

| Key | Tap | Double Tap | Hold |
|-----|-----|------------|------|
| Super Caps (CapsLock position) | Escape | Toggle Numpad Layer | Momentary Numpad Layer |
| Productivity (Right Ctrl) | Copy (Ctrl/Cmd+C) | Paste (Ctrl/Cmd+V) | Cut (Ctrl/Cmd+X) |
| Encoder Button | Mute | Play/Pause | - |

## Encoder Functions

- **Default**: Volume up/down
- **Left Shift + turn**: Change layers
- **Right Shift + turn**: Page up/down
- **Left Ctrl + turn**: Navigate words
- **Right Alt + turn**: RGB hue
- **Left Alt + turn**: Media track next/prev
- **FN layer**: RGB timeout adjustment

## Quick Settings

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

## Building

```bash
just build    # Compile firmware
just flash    # Compile and flash
just dev      # Generate clangd config
just lint     # Check for errors
```
