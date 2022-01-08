# IDOBAO ID67

A 65% hotswap keyboard from IDOBAO.

![ID67](https://cdn.shopify.com/s/files/1/0382/1348/4675/products/0cdd9177ff42157dcd7fb15650b156a1.png?v=1632918941)

Idobao ID67 & ID67V2 (incl. ID67 Crystal & ID67 Bestype) 65% hot-swappable mechanical keyboard kit*

* __Keyboard Maintainer:__
  - v1 - Tybera
  - v2 - Vino Rodrigues ([@vinorodrigues](https://github.com/vinorodrigues))
* __Hardware Supported:__ IDOBAO ID67 (v1 & v2)
* __Hardware Availability:__
  - v1 - [Idobao.net](https://www.idobao.net/products/idobao-id67-65-hot-swappable-mechanical-keyboard-kit-1), [AliExpress](https://www.aliexpress.com/item/1005002871249832.html)
  - v2 - [Idobao.net](https://idobao.net/collections/65-layout/products/idobao-id67v2-65-hot-swappable-mechanical-keyboard-kit)
    - ID67 Crystal - [Idobao.net](https://idobao.net/collections/65-layout/products/idobao-id67-crystal-keyboard-kit-gasket-mount-version)
    - ID67 Bestype - [Idobao.net](https://idobao.net/collections/65-layout/products/idobao-id67-bestype-keyboard-kit-aluminum-with-brass-weight) 

Make example for this keyboard (after setting up your build environment):

    make idobao/id67/v1:default
    make idobao/id67/v2:default

Flashing example for this keyboard:

    make idobao/id67/v1:default:flash
    make idobao/id67/v2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB * **Keycode in layout**: Press the key mapped to `RESET` if it is available
