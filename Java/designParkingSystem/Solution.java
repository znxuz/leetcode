
package designParkingSystem;

class Solution {

	class ParkingSystem {

		int[] slots;

		public ParkingSystem(int big, int medium, int small) {
			slots = new int[]{big, medium, small};
		}
		
		public boolean addCar(int carType) {
			if (slots[carType - 1] == 0)
				return false;
			slots[carType - 1]--;
			return true;
		}
	}

}

