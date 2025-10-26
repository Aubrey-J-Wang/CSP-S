$\mathbf{Program}\text{ Dijkstra+Heap}$
$---------------------$
$\mathbf{Input} \text{: Graph } G.$
$\mathbf{Output} \text{: The minimum length for all vertices }i\text{ to vertex 1.}$

$01\mid \mathbf{Program\ begin}$
$02\mid\mathrm{vector}\ gv^{\mathrm{pair}}_{1,2,\cdots,100005} \gets \emptyset $
$03\mid\mathrm{greater\ priority\ queue\ \mathit{pq}_{pair}\gets \empty}$
$04\mid\mathrm{dist}_{0,1,\cdots,100001} \gets \infty,\mathrm{visited_{0,1,\cdots,100001} \gets \mathrm{false}}$
$05\mid$
$06\mid\mathbf{Procedure\ }  \text{dijkstra()}\text{:}$
$07\mid\ \ \ \ \mathrm{dist_1 \gets 0, visited_1 \gets \mathrm{true}}$
$08\mid\ \ \ \ \mathrm{push\ (0,0)\ to\ } pq$
$09\mid\ \ \ \ \mathbf{While}\ pq\mathrm{\ is \ not \ empty\ \mathbf{do}\text{:}}$
$10\mid\ \ \ \ \ \ \ \ x\ \mathrm{ \gets first\ element\ of\ top\ of\ pq}$
$11\mid\ \ \ \ \ \ \ \ \mathrm{pop\ front\ of\ }pq$
$12\mid\ \ \ \ \ \ \ \ \mathrm{IF\ \mathrm{visited}_\mathit x = true\text{: Continue with next loop}}$
$13\mid\ \ \ \ \ \ \ \  \mathrm{visited}_x \gets \text{true}$
$14\mid\ \ \ \ \ \ \ \ \mathrm{\forall\  pair}\ v\in gv_x\ \mathbf{do}\text{:}$
$15\mid\ \ \ \ \ \ \ \ \ \ \ \ {u \gets \text{first of }v; w \gets \text{second of }v}$
$16\mid\ \ \ \ \ \ \ \ \ \ \ \ {\mathbf{if}\ \mathrm{dist}_x+w < \mathrm{dist}_u \ \mathrm{and}\ \mathrm{visited}_u \ne \text{true}}\text{:}$
$17\mid\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ {\mathrm{dist}_u \gets \text{dist}_x+w}$
$18\mid\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \mathrm{push}\ (y,\text{dist}_y)\ \mathrm{to\ front\ of\ }pq$
$19\mid$
$20\mid n,m,k \gets \mathrm{input\ in\ order}$
$21\mid \mathbf{For}\ n\mathrm{\ times\ \mathbf{do}\text{:}}$
$22\mid \ \ \ \ u,v,w \gets \mathrm{input\ in\ order}$
$23\mid \ \ \ \ \mathrm{push\ }(v,w)\ \mathrm{to\ back\ of\ }gv_u$
$24\mid \mathrm{dijkstra()}$
$25\mid \forall\ i\in \mathrm{dist}\ \mathbf{do}\text{: } \mathrm{print}\ i\ \mathrm{with}\ \text{half-width break}$
$26\mid$
$27\mid\mathbf{Program\ end}$
