# Matrix multiplication using HPX

This program parallelly multiplies two randomly generated matrices using [HPX](https://github.com/STEllAR-GROUP/hpx).

## Table of contents

- [Matrix multiplication using HPX](#matrix-multiplication-using-hpx)
  - [Table of contents](#table-of-contents)
  - [Building](#building)
  - [Running](#running)
  - [Example](#example)
  - [License](#license)

## Building

1. [Install CMAKE](https://cmake.org/install/).
2. [Install HPX](https://hpx-docs.stellar-group.org/latest/html/manual/getting_hpx.html).
3. Clone this repository and `cd` into the directory where you cloned it.
4. Issue `mkdir build && cd build && cmake .. && make`

On Fedora, installing CMAKE and HPX can be done by issuing the following command:

`sudo dnf install cmake hpx-devel -y`

## Running

If you followed the setps outlined above and the build succeeded, you should a binary named `gsoc-hpx-project` in the `build/bin` directory. Run the binary like:

`gsoc-hpx-project --r1 <matrix1-number-of-rows> --c1 <matrix1-number-of-columns> --r2 <matrix2-number-of-rows> --c2 <matrix2-number-of-columns>`

`r1`, `c1`, `r2`, `c2` cannot be zero and `c1` must be equal to `r2` for multiplication to take place. If no values are provided for these variables, `3` is assumed.

You can run the binary with `-h` flag to see extensive options available.

## Example

```bash
gsoc-hpx-project --r1 4 --c1 4 --r2 4 --c2 4
generating matrix 1 (4x4)..
genrated matrix 1:

550.916 975.525 417.399 501.632 
425.883 751.824 663.729 578.061 
968.433 308.673 255.124 254.536 
227.921 500.173 728.237 846.505 

generating matrix 2 (4x4)..
genrated matrix 2:

830.029 105.374 649.669 41.8664 
23.7258 653.038 441.373 179.365 
655.402 499.135 311.425 527.879 
396.32 192.992 397.576 128.687 

multiplying the matrices..
result:

952792 1.00026e+06 1.11791e+06 482930 
1.03544e+06 978698 1.04504e+06 577439 
1.07924e+06 480087 946050 263340 
1.01382e+06 877506 932177 592612 

exiting..                                
```

## License

GPLv3
