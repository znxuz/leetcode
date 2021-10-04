// https://leetcode.com/problems/read-n-characters-given-read4/

package read4;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf4);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
public class Solution extends Reader4 {

	// static variables mess up the solutions
	private final char[] sBuf = new char[4];
	private int sBufLen = 0;
	private int sBufIndex = 0;

    public int read(char[] buf, int n) {
		System.out.println("" + sBufLen + sBufIndex);
		int readLen = 0;

		while (sBufIndex < sBufLen && n-- > 0) {
			buf[readLen++] = sBuf[sBufIndex++];
		}

		while (n > 0) {
			sBufLen = read4(sBuf);
			if (sBufLen == 0)
				break;
			sBufIndex = 0;
			while (sBufIndex < sBufLen && n-- > 0) {
				buf[readLen++] = sBuf[sBufIndex++];
			}
		}

		return readLen;
    }
}
