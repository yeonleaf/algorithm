/*
root, root+left, root+right, root+left+right
여기까지는 잘 접근함 
하지만 재귀함수를 사용해서 구할 때는 유의할 점이 있는데
리턴할 때는 root+left+right를 리턴하면 안 됨
그 이유는 root를 두 번 방문하지 않고 root+left+right를 구할 수 있는 방법이 없기 때문
*/

import java.util.*;

class Solution {
    private int maxSum;

    public int maxSumHelper(TreeNode root) {
		
		// base case
        if (root == null) return 0; 
		
		// recursing through left and right subtree
        int leftMax = maxSumHelper(root.left);
        int rightMax = maxSumHelper(root.right);

		// finding all the four paths and the maximum between all of them
        int maxRightLeft = Math.max(leftMax, rightMax);
        int maxOneNodeRoot = Math.max(root.val, (root.val + maxRightLeft));
        int maxAll = Math.max(maxOneNodeRoot, leftMax + rightMax + root.val);
		
		// Storing the result in the maxSum holder
        maxSum = Math.max(maxSum, maxAll);
		
		// returning the value if root was part of the answer
        return maxOneNodeRoot;

    }

    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        maxSumHelper(root);
        return maxSum; // as maxSum will always store the result

    }
}
