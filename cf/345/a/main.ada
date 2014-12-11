with Ada.Text_IO; use Ada.Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Main is
    s: String(1..50);
    l: Natural;
    p: Float;
    c: Float;
begin
    Get_Line(s, l);
    Get(p);
    c := 0.0;
    for i in 1..l loop
        if s(i) = '1' then
            c := c+1.0;
        end if;
        if s(i) = '?' then
            c := c+p;
        end if;
    end loop;
    c := c/Float(l);
    Put(Item => c, Aft => 5, Exp => 0);
end Main;
