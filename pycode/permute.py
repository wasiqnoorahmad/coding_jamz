""" 
Given a string, this program computes all the permutation of it.

"""


def permute_all(src, n, lvl=0):
    if n - lvl == 1:
        print("".join(src))
        return

    for i in range(lvl, n):
        src[lvl], src[i] = src[i], src[lvl]
        permute_all(src, n, lvl+1)
        src[lvl], src[i] = src[i], src[lvl]


def main():
    src = ["A", "B", "C", "E"]
    permute_all(src, len(src))


if __name__ == "__main__":
    main()
