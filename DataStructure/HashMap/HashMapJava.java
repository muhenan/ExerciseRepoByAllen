package DataStructure.HashMap;

import java.util.HashMap;
import java.util.HashSet;

class HashMapJava{

// leetcode 535 TinyURL 加密与解密

/*

哈利表是从零开始往里放的

*/

HashMap<Integer, String> map = new HashMap<>();
int i = 0;
public String encode(String longUrl) {
    map.put(i, longUrl);
    return "http://tinyurl.com/" + i++;
}
public String decode(String shortUrl) {
    return map.get(Integer.parseInt(shortUrl.replace("http://tinyurl.com/", "")));
}


/*

两数之和

这种做法可以说是非常漂亮，但是这个有一个很重要的地方，就是用了Java强大的容器
一个哈希表，key 是 值，value 是 index
每一个都这样存下来，到下一个是找是不是有对应的那个值，找到就返回相应的index

非常简洁非常漂亮，Java强大容器的使用

存储和遍历

*/
public int[] twoSum(int[] nums, int target) {
    HashMap<Integer, Integer> indexForNum = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        if (indexForNum.containsKey(target - nums[i])) {
            return new int[]{indexForNum.get(target - nums[i]), i};
        } else {
            indexForNum.put(nums[i], i);
        }
    }
    return null;
}

/*

217 重复元素

Java强大的 set

*/

public boolean containsDuplicate(int[] nums) {
    HashSet<Integer> set = new HashSet<>();
    for (int num : nums) {
        set.add(num);
    }
    return set.size() < nums.length;
}


//594. Longest Harmonious Subsequence (Easy)

/*

note 大神方法 ：
    先计数，用hashmap计数，注意getOrDefault的应用
    找最大值，遍历一遍，得他和他后一个的个数和（前提的有后一个）

*/

public int findLHS(int[] nums) {
    HashMap<Integer, Integer> countForNum = new HashMap<>();
    for (int num : nums) {
        countForNum.put(num, countForNum.getOrDefault(num, 0) + 1);
    }
    int longest = 0;
    for (int num : countForNum.keySet()) {
        if (countForNum.containsKey(num + 1)) {
            longest = Math.max(longest, countForNum.get(num + 1) + countForNum.get(num));
        }
    }
    return longest;
}






















}