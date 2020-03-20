# ObfuscationPlayground

[![js-semistandard-style](https://img.shields.io/badge/code%20style-semistandard-brightgreen.svg?style=flat-square)](https://github.com/standard/semistandard)  ![stability-unstable](https://img.shields.io/badge/stability-unstable-yellow.svg)

An easily auditable web application for generating cryptographic hashes and obfuscating small amounts of data.

Under construction (but mainly works). Version -1/π. The supplied obfuscation plugins are intentionally weak, since it seems that many legal systems have decided that strong encryption is equivalent to lethal armament.

## Background

I created a private version of something like this many years ago, but it was all in JS and relied on an included, minified block of code from a JS crypto library. A monstrosity which was totally (at least for me) unauditable. (But with a cute macro language similar to the FALSE language!)

But now, because of the very limited interface between WebAssembly and JS, it is now possible to make the equivalent with less than 300 un-minified lines of JS, and almost not have to worry about auditing the WebAssembly plugins because they have no way (barring bugs in browser implementation) to exfiltrate data (unless you implement obfuscations with ciphertext expansion, I suppose).

## Building

To build, you must first clone two other repositories into "plugins/common" as described in "plugins/common/NOTES". You will also need a recent version of clang which supports WebAssembly as a backend.

The plugins include code from various sources, which have lenient licenses. This Readme will eventually list them properly.

## Tips

The "URIError: malformed URI sequence" error means that you are trying to display, as a string, binary data which is not really a binary-encoded string --- choose a more appropriate output format.

The only supplied plugin which takes parameters is "obfus-2" ("Obfuscation 2" in the dropdown menu). It takes one parameter at index 0, which is expanded using a non-cryptographic PRNG to 12 bytes which are used as a key for a Vigenère cipher.

When setting a parameter, the parameter value can be in any format which Javascript's parseInt() understands, so binary values (for example, generated by hash functions) can be input in hexadecimal by prepending "0x". Parameter values are limited to 32 bits because of current WebAssembly limitations.
