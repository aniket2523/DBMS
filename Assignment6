Delimiter $$
create Trigger back 
Before insert on
student for each row 
begin 
insert into backup (sid,sname,smarks)
values (new.sid,new.sname,new.smarks );
end $$
