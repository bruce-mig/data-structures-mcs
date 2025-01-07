## Graph Abstract Data Type (FIFO)

#### Definition

A graph `G` is an ordered pair of a set `V` of vertices and a set `E` of edges.

`G = (V,E)`

`|V|` - number of vertices  
`|E|` - number of edges

#### Number of edges

if |V| = n

then,

0 <= |E| <= n(n-1), if directed
0 <= |E| <= n(n-1)/2, if undirected

assuming no self loop or multi-edge

#### Properties of Graphs

- walk - a sequence of vertices where each adjacent pair is connected by an edge.
- path - a walk in which no vertices (and thus no edges) are repeated.
- trail - a walk in which no edges are repeated.

