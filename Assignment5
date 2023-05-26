delimiter $$
create procedure (IN r int(5) , IN b int(5) , IN dr date )
Begin
declare r int ;
declare  b int ;
declare dr date;
declare a  int;
declare n  int;
declare i  date;
update student set dor =dr where rno = r AND bid = b;
select doi from student into i where  rno = r AND bid = b;
set n = DATEDIFF (dr,i);

if n <= 10 then 
set a = 0;
update books set amt = a , status = 'R' where rno = r AND bid = b;

else if (n >= 11 and n <= 30) then 
set a = n*5 ;
update books set amt = a , status = 'R' where rno = r AND bid = b;

else if (n > 30) then 
set a = n*10 ;
update books set amt = a , status = 'R' where rno = r AND bid = b;

end if

update books set amt = a where rno = r AND bid = b;
 
end $$
delimiter ;
