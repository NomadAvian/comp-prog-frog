# Number Theory

## Fundamental Theorem of Number Theory

$$
    N = p_1^{a_1}p_2^{a_2}...p_n^{a_n}
$$

# Combinatorics

## Combinations and Permutations

## Stars and Bars

How many ways are there to place $n$ different objects in $m$ different boxes?

$$
    { n + m - 1 \choose n }
$$

## Catalan Numbers

Sequence of *Catalan Numbers* is,

$$
    C_n = {1 \over n + 1} {2n \choose n}
$$

### Catalan Convolutions

> What does it mean?

$$
    C_n^i = {k + 1 \over n + k + 1} {2n + k \choose n}
$$

## Lucas Theorem

if, $1 \leq N, K \leq 10^9$ and $P \leq N, K$,

$$
    { N \choose K } \mod P \equiv \prod { n_i \choose k_i } \mod P
$$

Here, $n_i$ and $k_i$ are respectively the $i$th digit of $N$ and $K$ expressed in base $P$.

### Application

1. ${n\choose k} \mod p$
2. ${n\choose k} \mod m$, where $m = p_1p_2$ (Apply CRT)
3. Number of elements divisible by $P$ in the $n$th row of Pascal's Triangle