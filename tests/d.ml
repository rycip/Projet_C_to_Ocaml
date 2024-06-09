let x = ref ( 0 ) in 
(*  boo *)
let y = ref ( 3 + !x ) in 
(*  x = y + 1; *)
y := 85 + !x + !x / !y ; 
x := !x * !y * 2 ; 
let while_a = ref ( true  ) in 
while_a := false  && !while_a ; 
Printf.printf "%d %d\n" ( 3 * !x + !y - 4 ) !y ; 
let i = ref ( 0 ) in 
while ( !i = 0 ) do 
 !i := !i + 1 ; 
;;;;