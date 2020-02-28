#! /bin/bash
cat <<'EOF'
// This file is generated automatically by assemble_plugins.bash, do not make changes here!
var wasmPlugin = {};

EOF

names=`find plugins -name plugins -o -type d -prune | sed -e 's/plugins.//g'`

for name in $names; do
    if [ $name != "plugins" ] && [ -r plugins/${name}/${name}.wasm ]; then
        if [ -r plugins/${name}/memory_namespace ]; then
            memory_namespace=`cat plugins/${name}/memory_namespace`
        else
            memory_namespace="${name}"
        fi
	echo -n "wasmPlugin['"
        echo -n ${name}
        echo -n "'] = ['"
        echo -n ${memory_namespace}
        echo -n "', \`"
	base64 plugins/${name}/${name}.wasm | head -c -1
	echo '`];'
	echo
    fi
done
