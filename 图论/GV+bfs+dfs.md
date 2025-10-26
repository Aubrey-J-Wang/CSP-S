$\mathbf{Program}\text{ gv+bfs+dfs}$
$---------------------$
$\mathbf{Input} \text{: Graph }G.$
$\mathbf{Output} \text{: Sequence of visiting } G \text{ using DFS and BFS.}$

$01\mid \mathbf{Program\ begin }$
$02\mid \mathrm{n,m \gets input\ in\ order}$
$03\mid \mathrm{vector\ gv_{1,2,\cdots, 101}^\N} \gets \empty$
$04\mid \mathrm{vis_{1,2,\cdots,101}\gets false}$
$05\mid \mathrm{ }$
$06\mid \mathrm{FOR\ m\ times\ DO\text{:}}$
$07\mid \mathrm{\ \ \ \ x,y \gets input\ in\ order }$
$08\mid \mathrm{\ \ \ \ push\ y\ to\ back\ of\ gv_x}$
$09\mid \mathrm{ }$
$10\mid \mathrm{FUNCTION\ dfs(k_\N)\text{:}}$
$11\mid \mathrm{\ \ \ \ vis_k \gets true}$
$12\mid \mathrm{\ \ \ \ \text{print k with half-width break}}$
$13\mid \mathrm{\ \ \ \ \forall\ i \in gv_k\ DO\text{:} }$
$14\mid \mathrm{\ \ \ \ \ \ \ \ IF\ vis_i = false\text{: dfs(i)} }$
$15\mid \mathrm{ }$
$16\mid \mathrm{FUNCTION\ bfs(st_\N)\text{:} }$
$17\mid \mathrm{\ \ \ \ queue\ q_\N \gets \empty }$
$18\mid \mathrm{\ \ \ \ push\ st\ to\ back\ of\ q }$
$19\mid \mathrm{\ \ \ \ vis_st \gets true}$
$20\mid \mathrm{\ \ \ \ WHILE\text{ q is not empty DO:} }$
$21\mid \mathrm{\ \ \ \ \ \ \ \ now \gets front\ of\ q }$
$22\mid \mathrm{\ \ \ \ \ \ \ \ \text{print now with half-width break} }$
$23\mid \mathrm{\ \ \ \ \ \ \ \ pop\ front\ of\ q }$
$24\mid \mathrm{\ \ \ \ \ \ \ \ \forall\ i \in v_now\ DO\text{:} }$
$25\mid \mathrm{\ \ \ \ \ \ \ \ \ \ \ \ IF\ vis_i = false\ DO\text{:}}$
$26\mid \mathrm{\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ push\ i \ to \ back\ of\ q }$
$27\mid \mathrm{\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ vis_i \gets true }$
$28\mid \mathrm{ }$
$29\mid \mathrm{dfs(1) }$
$30\mid \mathrm{print\ endline }$
$31\mid \mathrm{vis_{1,2,\cdots 101} \gets false }$
$32\mid \mathrm{bfs(1) }$
$33\mid \mathrm{}$
$34\mid \mathrm{PROGRAM\ END }$
