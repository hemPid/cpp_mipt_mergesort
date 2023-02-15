import matplotlib.pyplot as plt

#open('insert.txt', 'r')

ns = []
d = []
ins = []

with open('default.txt', 'r') as f:
	for line in f:
		l = line.rstrip().split(" ")
		ns.append(float(l[0]))
		d.append(float(l[1]))


with open('insert.txt', 'r') as f:
	for line in f:
		l = line.rstrip().split(" ")
		ins.append(float(l[1]))

plt.plot(ns, d, ns, ins)
plt.show()