#ifndef lc223_h
#define lc223_h

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);

		if (C < E || G < A) return area1 + area2;
		if (D < F || H < B) return area1 + area2;

		int bottom_left[2], top_right[2];
		bottom_left[0] = (A > E) ? A : E;
		bottom_left[1] = (B > F) ? B : F;
		top_right[0] = (C < G) ? C : G;
		top_right[1] = (D < H) ? D : H;

		return area1 + area2 - (top_right[0] - bottom_left[0]) * (top_right[1] - bottom_left[1]);
	}
};

#endif