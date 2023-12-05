#include <stdio.h>
#include <windows.h>
#include "main.h"
#include "info.h"
#include "intro.h"
#include "stable.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "sequential.h"
#include "shell.h"
#include "quick.h"
#include "merge.h"
#include "heap.h"
#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "kruskal.h"
#include "prim.h"
#include "topological.h"


int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			int introCode = introDraw();
			if (introCode == 0) {
				int sta = stable();
				if (sta == 0) {
					bubble();
				}
				else if (sta == 2) {
					selection();
				}
				else if (sta == 4) {
					insertion();
				}
				else if (sta == 6) {
					sequential();
				}
				else if (sta == 8) {
					shell();
				}
				else if (sta == 10) {
					quick();
				}
				else if (sta == 12) {
					merge();
				}
				else if (sta == 14) {
					heap();
				}
				else if (sta == 16) {
					return 0;
				}
			}
			else if (introCode == 2) {
				int gra = graph();
				if (gra == 0) {
					bfs();
				}
				else if (gra == 2) {
					dfs();
				}
				else if (gra == 4) {
					kruskal();
				}
				else if (gra == 6) {
					prim();
				}
				else if (gra == 8) {
					topological();
				}
				else if (gra == 10) {
					return 0;
				}
			}
			else if (introCode == 4) {
				
			}
		}
		else if (menuCode == 1) {
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
}