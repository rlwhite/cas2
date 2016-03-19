setenv CAS_BIN $CAS_DIR/bin/
setenv CAS_LIB $CAS_DIR/lib/
setenv CAS_SRC $CAS_DIR/src/
setenv CAS_INC $CAS_DIR/include/
setenv CAS_TEST $CAS_SRC/casTest/

echo "LD_LIBRARY_PATH: $LD_LIBRARY_PATH"
echo "CAS_LIB: $CAS_LIB"

setenv LD_LIBRARY_PATH {$CAS_LIB}:$LD_LIBRARY_PATH

