
import binarytree
import treeprinter


if __name__ == "__main__":
    #              .--100
    #        .--177
    #       |      `--468
    #  --792
    #       |                  .--132
    #       |            .--592
    #       |           |      `--310
    #       |      .--135
    #       |     |      `--366
    #       |     |            `--687
    #        `--566
    #  Preorder: 792 566 135 366 687 592 310 132 177 468 100
    #  Inorder: 566 687 366 135 310 592 132 792 468 177 100

    preord = [792, 566, 135, 366, 687, 592, 310, 132, 177, 468, 100]
    inord  = [566, 687, 366, 135, 310, 592, 132, 792, 468, 177, 100]
    t = binarytree.build_from_traversals(preord, 0, 11, inord, 0, 11)
    treeprinter.draw_tree(t)
    print('Preorder: ', end='')
    binarytree.preorder_print(t)
    print()
    print('Inorder: ', end='')
    binarytree.inorder_print(t)
    print()

