
# Probabilities that offspring will have dominant trait:
# k/_ => 4/4
# m/m => 3/4
# n/m => 2/4

k = 2
m = 2
n = 2
T = k + m + n * 1.0

# Each outcome can be plotted on a tree with 3 branches
# from the root (k, m, n) and three more branches from
# each of those first set of leaves:
#
#        k
#      /
#    k - m
#   /  \
#  /     n
#R - m ...
#  \ n ...

# The following equation computes each possible outcome
# and multiplies the probability of each outcome by the
# probability that the outcome can result in an offspring
# with a dominant trait
print \
    (1.0 * ((n/T) * ((k)/(T-1)))) + \
    (.50 * ((n/T) * ((m)/(T-1)))) + \
    (1.0 * ((k/T) * ((n)/(T-1)))) + \
    (1.0 * ((k/T) * ((k-1)/(T-1)))) + \
    (1.0 * ((k/T) * ((m)/(T-1)))) + \
    (.50 * ((m/T) * ((n)/(T-1)))) + \
    (1.0 * ((m/T) * ((k)/(T-1)))) + \
    (.75 * ((m/T) * ((m-1)/(T-1))))

# Notes:
#Pr(X=k) = k/T
#Pr(X=m) = m/T
#
#X=k, Pr(Y=k)=(k-1)/(T-1) => (k/T) (k-1)/(T-1)
#X=k, Pr(Y=m)=(m)/(T-1) => (k/T) (m)/(T-1)
#X=m, Pr(Y=k)=(k)/(T-1) => (m/T) (k)/(T-1)
#X=m, Pr(Y=m)=(m)/(T-1) => (m/T) (m-1)/(T-1) * 1/2
