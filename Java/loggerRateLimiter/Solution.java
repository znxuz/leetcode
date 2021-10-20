// https://leetcode.com/problems/logger-rate-limiter/

package loggerRateLimiter;

import java.util.HashMap;
import java.util.Map;

class Logger {

	private final Map<String, Integer> map = new HashMap<>();

    public Logger() {
    }
    
    public boolean shouldPrintMessage(int timestamp, String message) {
		if (timestamp < map.getOrDefault(message, 0))
			return false;
		map.put(message, timestamp + 10);
		return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
