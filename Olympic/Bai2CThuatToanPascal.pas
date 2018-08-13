{

	Fx[j]:=Fx[j]+Fx[j-p]; 
	for i:=2 to n do 
		if nto(i) then 
			begin 
				Fx[i]:=Fx[i]+1; 
				for j:=i+2 to n do 
				Fx[j]:=Fx[j]+Fx[j-i]; 
			end;
}

uses crt; 
const 	fi='Prime.inp'; 
		go='Prime.out'; 
type arr=array[1..50] of byte; 
var n,k,dem :longint; 
	Fx :array[0..2000] of ^arr; 
	Donvi :arr; 
	p :pointer; 
	f,g :text;
	
procedure Openf; 
	begin 
		assign(f,fi); 
		reset(f); 
		assign(g,go); 
		rewrite(g); 
	end; 

procedure Closef; 
	begin 
		close(f); 
		close(g); 
	end;
	
procedure Input; 
	begin 
		readln(f,n); 
		donvi[1]:=1; 
	end; 
	
function nto(p:longint):boolean; 
	var k:longint; 
	begin 
		Nto:=false; 
		for k:=2 to round(sqrt(p)) do 
			if p mod k=0 then exit; 
		Nto:=true; 
	end;
	
procedure Print; 
	var i:integer; 
	begin 
		for i:=k downto 1 do 
			write(g,fx[n]^[i]); 
	end;
	
procedure Cong(a,b:arr;var c:arr); 
	var i,du :integer; 
	begin 
		i:=0; 
		du:=0; 
		while i<> 
			begin 
				inc(i);
				c[i] :=(a[i]+b[i]+du) mod 10;
				du :=(a[i]+b[i]+du) div 10;
			end; 
		if du<>0 then 
			begin 
				i:=i+1; 
				c[i]:=du; 
			end; 
		k:=i; 
	end;
	
Procedure Main; 
	var i,j:integer; 
	begin 
		for i:=1 to n do 
			begin 
				Fx[i]:=Fx[i]+1; 
				for j:=i+1 to n do 
					Fx[j]:=Fx[j]+Fx[j-i]; 
			end; 
	end;
	
begin 
	clrscr; 
	Mark(p); 
	openf; 
	Input; 
	Main; 
	Print; 
	release(p); 
	Closef; 
end.





{
	Procedure Main; 
		var i,j:integer; 
		begin 
			k:=1; 
			for i:=1 to n do 
				begin 
					New(Fx[i]); 
					fillchar(fx[i]^,sizeof(fx[i]^),0); 
				end; 
			for i:=2 to n do 
				if nto(i) then 
					begin 
						Cong(Fx[i]^,donvi,Fx[i]^); 
						for j:=i+2 to n do 
							Cong(Fx[j]^,Fx[j-i]^,Fx[j]^); 
					end; 
		end; 
}