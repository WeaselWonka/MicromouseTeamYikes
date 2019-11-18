# takes in the text from https://github.com/micromouseonline/mazefiles/tree/master/classic
# outputs the text needed to run the maze in the c++ code

upper = ""
lower = ""

for i in range(33):
    line = input().rstrip()
    if i % 2 == 0:
        upper += " ".join("1" if ("-" == elem)else "0" for elem in line[2::4]) + "\n";
    else:
        lower += " ".join("1" if ("|" == elem) else "0" for elem in line[::4]) + "\n";

print(upper + lower)
