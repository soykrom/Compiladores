export CVS_RSH=ssh
export PATH="$PATH:/home/soykrom/compiladores/root/usr/bin"
cd ../fir;  make; cd ../tests
for x in *.fir; do
    echo "TESTE $(basename -- "$x")"
    ../fir/fir ./$x
    filename=$(basename -- "$x")
    yasm -felf32 "${filename%.*}".asm 
    ld -m elf_i386 -o "${filename%.*}" "${filename%.*}".o -L /home/catarina/compiladores/root/usr/lib -lrts
    ./"${filename%.*}" > "${filename%.*}".out
    rm ./"${filename%.*}"

    diff -cBb -E -w "${filename%.*}".out ./expected/"${filename%.*}".out > ./diff/"${filename%.*}".diff
    if [ -s ./diff/"${filename%.*}".diff ]; then
        echo "FAIL: $x. See file $x:r.diff"
    else
        echo -n "."
        rm -f ./diff/"${filename%.*}".diff
    fi
done

rm -f *.o *.asm

echo "Done."

