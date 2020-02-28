PLUGINS = plugins/copy/copy.wasm plugins/md5/md5.wasm plugins/ripemd-160/ripemd-160.wasm plugins/sha-1/sha-1.wasm plugins/sha-224/sha-224.wasm plugins/sha-256/sha-256.wasm plugins/sha-384/sha-384.wasm plugins/sha-512/sha-512.wasm plugins/sha3-224/sha3-224.wasm plugins/sha3-256/sha3-256.wasm plugins/sha3-384/sha3-384.wasm plugins/sha3-512/sha3-512.wasm plugins/obfus-0/obfus-0.wasm plugins/obfus-1/obfus-1.wasm plugins/obfus-2/obfus-2.wasm 

wasm_plugins.js : ${PLUGINS}
	./assemble_plugins.bash > wasm_plugins.js

clean_wasm:
	rm plugins/*/*.wasm

# plugin targets follow

plugins/copy/copy.wasm : plugins/copy/copy.c
	cd plugins/copy; ../../compile_to_wasm_opt copy

plugins/md5/md5.wasm : plugins/md5/md5.c
	cd plugins/md5; ../../compile_to_wasm_opt md5

plugins/ripemd-160/ripemd-160.wasm : plugins/ripemd-160/ripemd-160.c
	cd plugins/ripemd-160; ../../compile_to_wasm_opt ripemd-160

SHA2_DIR = plugins/common/rfc6234
SHA2_DEPS = ${SHA2_DIR}/sha224-256.c ${SHA2_DIR}/sha384-512.c ${SHA2_DIR}/sha1.c ${SHA2_DIR}/sha.h ${SHA2_DIR}/sha-private.h

plugins/sha-1/sha-1.wasm : plugins/sha-1/sha-1.c ${SHA2_DEPS}
	cd plugins/sha-1; ../../compile_to_wasm_opt sha-1

plugins/sha-224/sha-224.wasm : plugins/sha-224/sha-224.c ${SHA2_DEPS}
	cd plugins/sha-224; ../../compile_to_wasm_opt sha-224

plugins/sha-256/sha-256.wasm : plugins/sha-256/sha-256.c ${SHA2_DEPS}
	cd plugins/sha-256; ../../compile_to_wasm_opt sha-256

plugins/sha-384/sha-384.wasm : plugins/sha-384/sha-384.c ${SHA2_DEPS}
	cd plugins/sha-384; ../../compile_to_wasm_opt sha-384

plugins/sha-512/sha-512.wasm : plugins/sha-512/sha-512.c ${SHA2_DEPS}
	cd plugins/sha-512; ../../compile_to_wasm_opt sha-512

SHA3_DIR = plugins/common/tiny_sha3
SHA3_DEPS = ${SHA3_DIR}/sha3.h ${SHA3_DIR}/sha3.c

plugins/sha3-224/sha3-224.wasm : plugins/sha3-224/sha3-224.c ${SHA3_DEPS}
	cd plugins/sha3-224; ../../compile_to_wasm_opt sha3-224

plugins/sha3-256/sha3-256.wasm : plugins/sha3-256/sha3-256.c ${SHA3_DEPS}
	cd plugins/sha3-256; ../../compile_to_wasm_opt sha3-256

plugins/sha3-384/sha3-384.wasm : plugins/sha3-384/sha3-384.c ${SHA3_DEPS}
	cd plugins/sha3-384; ../../compile_to_wasm_opt sha3-384

plugins/sha3-512/sha3-512.wasm : plugins/sha3-512/sha3-512.c ${SHA3_DEPS}
	cd plugins/sha3-512; ../../compile_to_wasm_opt sha3-512

plugins/obfus-0/obfus-0.wasm : plugins/obfus-0/obfus-0.c
	cd plugins/obfus-0; ../../compile_to_wasm_opt obfus-0

plugins/obfus-1/obfus-1.wasm : plugins/obfus-1/obfus-1.c
	cd plugins/obfus-1; ../../compile_to_wasm_opt obfus-1

plugins/obfus-2/obfus-2.wasm : plugins/obfus-2/obfus-2.c
	cd plugins/obfus-2; ../../compile_to_wasm_opt obfus-2

