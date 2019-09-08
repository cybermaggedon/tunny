
# Tunny Cipher Machine #

And unfinished Colossus emulator (ignore that).

## Build

```
make
```

## Use

Decrypt some messages...

```
./tunny -c cipherchallenge1.cfg -i cipherchallenge1.txt --decrypt
./tunny -c cipherchallenge2.cfg -i cipherchallenge2.txt --decrypt
./tunny -c cipherchallenge3.cfg -i cipherchallenge3.txt --decrypt
./tunny -c j3kf.cfg -i j3kf.txt --decrypt
./tunny -c j3ktikk4.cfg -i j3ktikk4.txt --decrypt
```

The J3 messages are real originals.  The cipherchallenge messages were
transmitted by Heinz Nixdorf Museum in Paderborn, Germany in TNOMC's
Cipher Challenge.  http://www.codesandciphers.org.uk/winner.html

There are a million settings, so it's easier to specify in a configuration
file, rather than on the command line.

Enjoy!

