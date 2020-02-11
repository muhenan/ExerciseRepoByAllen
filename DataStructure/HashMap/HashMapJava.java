package DataStructure.HashMap;

import java.util.HashMap;;

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










}