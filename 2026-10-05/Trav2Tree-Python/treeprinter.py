# Liberally adapted from 
# https://www.techiedelight.com/c-program-print-binary-tree/

from binarytree import TreePtr

# Global constant indices into the connector list
HORIZONTAL_LINE = 0
RIGHT_BRANCH    = 2
LEFT_BRANCH     = 3
CONNECTOR       = 4
SPACER          = 5

# Connectors
connectors = [
    "--",
    "|",
    ".--",
    "`--",
    "     |",
    "      "
]


class Trunk:
    def __init__(self, prev: Trunk | None, n: int) -> None:
        self.prev = prev
        self.connector_index = n

 
def show_trunks(p: Trunk | None) -> None:
    """ Helper function to print branches of the binary tree. """
    if p:
        show_trunks(p.prev)
        print(f'{connectors[p.connector_index]}', end='')


def draw_tree_helper(root: TreePtr, prev: Trunk | None, is_left: bool) -> None:
    if root:
        prev_connector = SPACER 
        trunk = Trunk(prev, prev_connector)
        draw_tree_helper(root.right, trunk, True)
        if not prev:
            trunk.connector_index = HORIZONTAL_LINE
        elif is_left:
            trunk.connector_index = RIGHT_BRANCH
            prev_connector = CONNECTOR
        else:
            trunk.connector_index = LEFT_BRANCH
            prev.connector_index = prev_connector
        show_trunks(trunk)
        print(f'{root.data}')
        if prev:
            prev.connector_index = prev_connector
        trunk.connector_index = CONNECTOR
        draw_tree_helper(root.left, trunk, False);

def draw_tree(root: TreePtr) -> None:
    draw_tree_helper(root, None, False)


