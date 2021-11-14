// https://leetcode.com/problems/can-place-flowers/

package canPlaceFlowers;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
		int i = 0, count = 0;
		while (i < flowerbed.length) {
			if (flowerbed[i] == 0
					&& (i == 0 || flowerbed[i - 1] == 0)
					&& (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i++] = 1;
				count++;
			}
			if(count>=n)
				return true;
			i++;
		}
		return false;
	}

	// time complexity: O(2n) = O(n)
	// space complexity: O(1)
	public boolean canPlaceFlowers2N(int[] flowerbed, int n) {
		prepare(flowerbed);
		for (int i = 0; i < flowerbed.length && n > 0; i++) {
			if (flowerbed[i] == 0) {
				int right = i == flowerbed.length - 1 ? i : i + 1;
				flowerbed[i] = flowerbed[right] = 1;
				n--;
				i++;
			}
		}

		return n == 0;
	}

	public void prepare(int[] flowerbed) {
		for (int i = 0; i < flowerbed.length; i++) {
			if (flowerbed[i] == 1) {
				int left = i == 0 ? 0 : i - 1;
				int right = i == flowerbed.length - 1 ? i : i + 1;
				flowerbed[left] = flowerbed[right] = 1;
				i++;
			}
		}
	}

}
