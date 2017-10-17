//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <set>
using namespace std;
struct point {
	int x, y;
};
struct comp {
  bool operator() (const point& lhs, const point& rhs) const
  {if (lhs.x!=rhs.x) {return lhs.x<rhs.x;} else {return lhs.y<rhs.y;}}
};

set<point, comp> po;
bool inset(int x, int y)
{
  point p;
  p.x = x;
  p.y = y;
  return (po.find(p) != po.end());
}
int main()
{
	pair<int, int> startpo;
	point p;
	int n, Min=1000000;
	int curx, cury, curs, lastx=-1, lasty=-1, lasts=-1, perimeter=0;
	int i;
	cin >> n;
	for(i=1;i<=n;i++){
   	cin >> p.x >> p.y, po.insert(p);
   	if(p.y<Min)
       	Min=p.y, startpo.first=p.x, startpo.second=p.y;
	}
	curx=startpo.first, cury=startpo.second, curs=3;
	while(true){
   	//cases
   	if(curs==1){
       	if(inset(curx-1, cury) && !inset(curx-1, cury+1) && (curx-1!=lastx || cury!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--;
       	}
       	else if(inset(curx+1, cury) && !inset(curx+1, cury+1) && (curx+1!=lastx || cury!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++;
       	}
       	else if(!inset(curx-1, cury) && !inset(curx-1, cury+1) && (curx!=lastx || cury!=lasty || lasts!=4)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=4;
       	}
       	else if(!inset(curx+1, cury) && !inset(curx+1, cury+1) && (curx!=lastx || cury!=lasty || lasts!=2)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=2;
       	}
       	else if(inset(curx-1, cury+1) && (curx-1!=lastx || cury+1!=lasty || lasts!=2)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--, cury++, curs=2;
       	}
       	else if(inset(curx+1, cury+1) && (curx+1!=lastx || cury+1!=lasty || lasts!=4)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++, cury++, curs=4;
       	}
   	}
   	else if(curs==2){
       	if(inset(curx, cury+1) && !inset(curx+1, cury+1) && (curx!=lastx || cury+1!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	cury++;
       	}
       	else if(inset(curx, cury-1) && !inset(curx+1, cury-1) && (curx!=lastx || cury-1!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	cury--;
       	}
       	else if(!inset(curx, cury+1) && !inset(curx+1, cury+1) && (curx!=lastx || cury!=lasty || lasts!=1)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=1;
       	}
       	else if(!inset(curx, cury-1) && !inset(curx+1, cury-1) && (curx!=lastx || cury!=lasty || lasts!=3)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=3;
       	}
       	else if(inset(curx+1, cury+1) && (curx+1!=lastx || cury+1!=lasty || lasts!=3)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++, cury++, curs=3;
       	}
       	else if(inset(curx+1, cury-1) && (curx+1!=lastx || cury-1!=lasty || lasts!=1)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++, cury--, curs=1;
       	}
   	}
   	else if(curs==3){
       	if(inset(curx-1, cury) && !inset(curx-1, cury-1) && (curx-1!=lastx || cury!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--;
       	}
       	else if(inset(curx+1, cury) && !inset(curx+1, cury-1) && (curx+1!=lastx || cury!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++;
       	}
       	else if(!inset(curx-1, cury) && !inset(curx-1, cury-1) && (curx!=lastx || cury!=lasty || lasts!=4)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=4;
       	}
       	else if(!inset(curx+1, cury) && !inset(curx+1, cury-1) && (curx!=lastx || cury!=lasty || lasts!=2)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=2;
       	}
       	else if(inset(curx-1, cury-1) && (curx-1!=lastx || cury-1!=lasty || lasts!=2)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--, cury--, curs=2;
       	}
       	else if(inset(curx+1, cury-1) && (curx+1!=lastx || cury-1!=lasty || lasts!=4)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx++, cury--, curs=4;
       	}
   	}
   	else if(curs==4){
       	if(inset(curx, cury+1) && !inset(curx-1, cury+1) && (curx!=lastx || cury+1!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	cury++;
       	}
       	else if(inset(curx, cury-1) && !inset(curx-1, cury-1) && (curx!=lastx || cury-1!=lasty || curs!=lasts)){
                	lastx=curx, lasty=cury, lasts=curs;
                	cury--;
       	}
       	else if(!inset(curx-1, cury+1) && !inset(curx, cury+1) && (curx!=lastx || cury!=lasty || lasts!=1)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=1;
       	}
       	else if(!inset(curx, cury-1) && !inset(curx-1, cury-1) && (curx!=lastx || cury!=lasty || lasts!=3)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curs=3;
       	}
       	else if(inset(curx-1, cury+1) && (curx-1!=lastx || cury+1!=lasty || lasts!=3)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--, cury++, curs=3;
       	}
       	else if(inset(curx-1, cury-1) && (curx-1!=lastx || cury-1!=lasty || lasts!=1)){
                	lastx=curx, lasty=cury, lasts=curs;
                	curx--, cury--, curs=1;
       	}
   	}
   	//update
   	perimeter++;
   	//base case
   	if(curx==startpo.first && cury==startpo.second && curs==3)
       	break;
	}
	cout << perimeter << endl;
	return 0;
}
