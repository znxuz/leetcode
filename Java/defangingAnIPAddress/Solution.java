// https://leetcode.com/problems/defanging-an-ip-address/

package defangingAnIPAddress;

class Solution {

    public String defangIPaddr(String address) {
		return String.join("[.]", address.split("\\."));
	}

    public String defangIPaddrBuilder(String address) {
		var stringBuilder = new StringBuilder();
		for (char c : address.toCharArray())
			stringBuilder.append((c == '.') ? "[.]" : c);

		return stringBuilder.toString();
	}

    public String defangIPaddrReplace(String address) {
		return address.replace(".", "[.]");
    }
}
