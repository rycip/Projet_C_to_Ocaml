let x = ref ( 0 ) in 
if (!x = 3) then begin
x := !x + 1
end
else if (!x = 2) then begin
x := 7;
x := !x + 1;
end;
 !x
;;
