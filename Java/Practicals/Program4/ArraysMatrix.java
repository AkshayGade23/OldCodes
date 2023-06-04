
public class ArraysMatrix {// clas starts here
    public static void main(String[] args) {
        int[][] matrix1 = { // matrix 1
            { 1, 2, 3 },
            { 4, 5, 6 }, 
            { 7, 8, 9 }, 
        }; 
        int[][] matrix2 = { // matrix 2
            { 1, 2, 3 }, 
            { 4, 5, 6 }, 
            { 7, 8, 9 }, 
        };
         
        int[][] additionMatrix = new int[3][3]; // matrix for additon
        int[][] subtractionMatrix = new int[3][3]; // matrix for subtraction
        int[][] multiplicationMatrix = new int[3][3]; // matrix for multiplication

        // Addition
        for (int i = 0; i < matrix1.length; i++) { //
            for (int j = 0; j < matrix1[i].length; j++) {
                // adding matrix1 element with matrix2
                additionMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        System.err.println("\nAddition Matrix =  \n");
        for (int i = 0; i < matrix1.length; i++) { //
            for (int j = 0; j < matrix1[i].length; j++) {
                System.out.print(additionMatrix[i][j] + " ");
            }
            System.out.println("");
        }

        // Subtraction
        for (int i = 0; i < matrix1.length; i++) { //
            for (int j = 0; j < matrix1[i].length; j++) {
                // adding matrix1 element with matrix2
                subtractionMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        System.err.println("\nSubtraction Matrix =  \n");
        for (int i = 0; i < matrix1.length; i++) { //
            for (int j = 0; j < matrix1[i].length; j++) {
                System.out.print(subtractionMatrix[i][j] + " ");
            }
            System.out.println("");
        }

        // Mutiplication
        if (matrix1[0].length != matrix2.length) {
            System.out.println(
                    "Mutiplication is not possible.\n Number of column of matrix 1 should be equal to number of row of matrix 2");
        } else {
            for (int i = 0; i < matrix1.length; i++) { //
                for (int j = 0; j < matrix1[i].length; j++) {
                    for (int k = 0; k < matrix1[i].length; k++) {
                        multiplicationMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
        }

        System.err.println("\nMultiplication cle Matrix =  \n");
        for (int i = 0; i < matrix1.length; i++) { //
            for (int j = 0; j < matrix1[i].length; j++) {
                System.out.print(multiplicationMatrix[i][j] + " ");
            }
            System.out.println("\n");
        }
    }
}
