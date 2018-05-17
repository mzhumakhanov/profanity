#ifndef HPP_HELP
#define HPP_HELP

#include <string>

const std::string g_strHelp = R"(
usage: ./profanity [OPTIONS]

  Basic modes:
    --benchmark             Run without any scoring, a benchmark.
    --zeros                 Score on zeros anywhere in hash.
    --letters               Score on letters anywhere in hash.
    --numbers               Score on numbers anywhere in hash.
    --mirror                Score on mirroring from center.

  Modes with arguments:
    --leading <single hex>  Score on hashes leading with given hex character.
    --matching <hex string> Score on hashes matching given hex string.

  Advanced modes:
    --leading-range         Scores on hashes leading with characters within
                            given range.
    --range                 Scores on hashes having characters within given
                            range anywhere.

  Range:
    -m, --min <0-15>        Set range minimum (inclusive), 0 is '0' 15 is 'f'.
    -M, --max <0-15>        Set range maximum (inclusive), 0 is '0' 15 is 'f'.

  Misc:
    -s, --skip <index>      Skip device given by index.
    -w, --work <size>       Set OpenCL local work size. [default = 64]
    -W, --workmax <size>    Set OpenCL maximum work size. [default = 1048576]

  Examples:
    ./profanity --leading f
    ./profanity --matching dead
    ./profanity --matching badXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXbad
    ./profanity --leading-range -m 0 -M 1
    ./profanity --leading-range -m 10 -M 12
    ./profanity --range -m 0 -M 1

  About:
    profanity is a vanity address generator for Ethereum that utilizes
    computing power from GPUs using OpenCL.

    Author: Johan Gustafsson <profanity@johgu.se>
    Beer donations: 0x000dead000ae1c8e8ac27103e4ff65f42a4e9203

  Disclaimer:
    Always verify that a private key generated by this program corresponds to
    the public key printed by importing it to a wallet of your choice. This
    program like any software might contain bugs and it does by design cut
    corners to improve overall performance.)";

#endif /* HPP_HELP */