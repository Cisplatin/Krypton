FILES=`find . -mindepth 2 -name "*.c"`
gcc $1 $FILES -std=c99 -lm
