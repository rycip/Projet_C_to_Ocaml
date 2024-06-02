let x = ref (0) in 
(*  boo *)
let y = ref (3 + !x) in 
(*  x = y + 1; *)
Printf.printf "%d %d\n" !x !y
;;