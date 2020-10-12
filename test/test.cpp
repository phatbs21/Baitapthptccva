var ch: char;
 a, b: array[‘a’..’z’] of longint;
function ok: boolean;
var i: char;
begin
 for i:=’a’ to ‘z’ do if a[i]<>b[i] then exit(false);
 exit(true);
end;
var i, t: longint;
 c: char;
BEGIN
 for t:=1 to 3 do
 begin
 for c:=’a’ to ‘z’ do
 begin a[c]:=0; b[c]:=0; end;
while not seekeoln do
 begin
 read(c);
 inc(a[c]);
 end;
 readln;
while not seekeoln do
 begin
 read(c);
 inc(b[c]);
 end;
 readln;
 if ok then writeln('YES') else writeln('NO');
 end;
