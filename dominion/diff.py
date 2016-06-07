import sys

f1 = temp
f2 = ../../sedwick/temp

l1 = []
l2 = []

n = 0
for l in open(f1):
        l1.append((n, l))
        n += 1

n = 0
for l in open(f2):
        l2.append((n, l))
        n += 1

for i in xrange(0, min(len(l1), len(l2))):
        (n, nl1) = li[i]
        (n, nl2) = l2[i]
        if nl1 != n12:
                print "lines don't match", i+1
                print f1, nl1[:-1]
                print f2, nl2[:-1]
                break
