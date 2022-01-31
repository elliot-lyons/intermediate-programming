#include "Rule.h"

int main() {
  
  Rule r("vp --> vb,adj");
  Rule r1("sa --> adj");
  Rule r2("er");
  Rule r3("ui --> hjh,dj,ee,l");

  r.show();
  r.show_mother();
  r.show_daughters();

  r1.show();
  r1.show_mother();
  r1.show_daughters();

  r2.show();
  r2.show_mother();
  r2.show_daughters();

  r3.show();
  r3.show_mother();
  r3.show_daughters();

  return 0;
}