
# Represents a node in a binary tree of integers
class TreeNode:
    def __init__(self, data: int) -> None:
        self.data = data
        self.left: TreePtr = None
        self.right: TreePtr = None


# The empty tree reference is None
TreePtr = TreeNode | None


def preorder_print(t: TreePtr) -> None:
    """ Prints the preorder traversal of the binary tree to 
        which t points. """
    if t:
        print(f'{t.data}', end=' ')
        preorder_print(t.left)
        preorder_print(t.right)


def inorder_print(t: TreePtr) -> None:
    """ Prints the inorder traversal of the binary tree to 
        which t points. """
    if t:
        inorder_print(t.left)
        print(f'{t.data}', end=' ')
        inorder_print(t.right)


def build_from_traversals(pre_order: list[int], pre_begin: int, pre_end: int,
                          in_order: list[int], in_begin: int, in_end: int) -> TreePtr:
    """ Builds a binary tree from its preorder and inorder traversals.
        pre_order is an array containing is a preorder traversal of a tree.
        in_order is an array containing is an inorder traversal of a tree.
        pre_begin is the starting index of the preorder traversal during this recursive call.
        pre_end is just after the last index of the preorder traversal during this recursive call.
        in_begin is the starting index of the inorder traversal during this recursive call.
        in_end is just after the last index of the inorder traversal during this recursive call. """

    # Replace with your code
    return None


