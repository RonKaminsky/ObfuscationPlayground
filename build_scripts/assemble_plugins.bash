#! /bin/bash
cat <<'EOF'
// This file is generated automatically by assemble_plugins.bash, changes will be overwritten upon rebuild!
var wasmPlugin = {};

EOF

names=`find plugins -name plugins -o -type d -prune | sed -e 's/plugins.//g'`

for name in $names; do
    if [ $name != "plugins" ] && [ -r plugins/${name}/${name}.wasm ]; then
	echo -n "wasmPlugin['"
        echo -n ${name}
        echo -n "'] = \`"
	base64 plugins/${name}/${name}.wasm | head -c -1
	echo '`;'
	echo
    fi
done
