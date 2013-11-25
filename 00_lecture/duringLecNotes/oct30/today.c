 Objectives
  1. Base conversions
  2. Exam review
 --------------------
1. Base Conversions
* Decimal (ie base 10)
   $243_{10} = 2 (10^2) + 4(10^1) + 3(10^0)$
* Hexadecimal (base 16) ( need to know )
    $15_{16} = F$
* Octal (base 8)
* Binary (base 2) (need to know)
    $0110_2=2^2+2^1=5$

--------------

3. Converting from any base to any other base (Count the place values)
     $1100101_2=(2^6)+(2^5)+(2^2)+(2^0) $

2. Base seven to ten
    $3624_{7}=3(7^3)+6(7^2)+2(7^1)+4(7^0)$

3.  Hexadecimal
    $0xA7_{16}=10(16^1)+7(16^0)$

4.  Base 10 to to another base
    $87_{10}=?_2$
    $(d_7d_6d_5d_4d_3d_2d_1d_0)_2= 2 mod 87$
    $d_0 = 1$
    87/2 = 43, 87%2 = 1
    43/2 = 21, 43%2 = 1
    21/2 = 10, 21%2 = 1
    10/2 = 5 , 10%2 = 0
    5/2  = 2 ,  5%2 = 1
    2/2  = 1 ,  2%2 = 0
    1/2 =  0 ,  1%2 = 1
    Ans: $87_{10}=1010111_2$

5. Base 10 to another base 16
    1637/16 = 102 , r = 5
    102/16 = 6    , r = 6

* To convert from a base to another base, where neither of the bases are base 10, use the two step process.
* Special case for $2^j$ to $2^k$ where k is a 2's multiple of j
    * Each Hexadecimal consists of 4 bits because 2^k = 16 , k = 4
        * $CA47_{16} =1100_2\ 0100_2\ 1010_2\ 0111_2  $
    * To go from base 2 to base 4 , right to left break each set of 4 binaries to groups of 2
        * $1100_2\ 0100_2\ 1010_2\ 0111_2  = 30102213_4$
    * To go from base 4 to base 8, group base 2 by sets of three and write left to right while reading binary right to left.
         <span style="color:red">$(00$</span> $1)(100)(010)(010)(100)(111)_2 =742241_8 $
--------------------

