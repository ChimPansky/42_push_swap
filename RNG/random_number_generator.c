/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_generator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:29:32 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/03 10:04:46 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

int is_duplicate(int num, int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
	int count = 0;
	int	cur;
	int	minval;
	int	maxval;

    printf("How many numbers u want, eh?: ");
    scanf("%d", &n);

	printf("Minval: ");
    scanf("%d", &minval);

	printf("Maxval: ");
    scanf("%d", &maxval);

    srand(time(NULL));

    int *numbers = malloc(n * sizeof(int));

    if (numbers == NULL) {
        return 1;
    }

    while (count < n) {
        int cur = (rand() % (maxval - minval + 1)) + minval;

        if (!is_duplicate(cur, numbers, count)) {
            numbers[count] = cur;
            count++;
        }
    }

	int	fd;
	char	*destination;
	destination = "input.txt";
	fd = open(destination, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);

    for (int i = 0; i < n; i++) {
		dprintf(fd, "%d ", numbers[i]);
    }
	printf("Numbers have been generated into Textfile: %s\n", destination);
	close(fd);
    free(numbers);
    return 0;
}
