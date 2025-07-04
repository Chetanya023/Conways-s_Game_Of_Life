const gridSize = 20;
const cellSize = 20;
let grid = new Array(gridSize).fill(null).map(() => new Array(gridSize).fill(0));
let intervalId = null;

function createGrid() {
    const gridContainer = document.querySelector('.grid-container');
    gridContainer.innerHTML = '';

    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            const cell = document.createElement('div');
            cell.className = 'cell';
            cell.style.width = `${cellSize}px`;
            cell.style.height = `${cellSize}px`;
            cell.addEventListener('click', () => toggleCellState(i, j));
            gridContainer.appendChild(cell);
        }
    }

    // Initialize all cells as alive
    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            grid[i][j] = 1;
        }
    }

    updateGrid();
}

function updateGrid() {
    const cells = document.querySelectorAll('.cell');
    cells.forEach((cell, index) => {
        const row = Math.floor(index / gridSize);
        const col = index % gridSize;
        if (grid[row][col] === 0) {
            cell.classList.add('dead');
        } else {
            cell.classList.remove('dead');
        }
    });
}

function toggleCellState(row, col) {
    grid[row][col] = 1 - grid[row][col];
    updateGrid();
}

function simulateGeneration() {
    if (!intervalId) {
        intervalId = setInterval(() => {
            for (let i = 0; i < gridSize; i++) {
                for (let j = 0; j < gridSize; j++) {
                    if ((i === 0 || i === gridSize - 1) && (j === 0 || j === gridSize - 1)) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
            updateGrid();
        }, 1000);
    }
}

document.getElementById('start-button').addEventListener('click', () => {
    simulateGeneration();
});

document.getElementById('stop-button').addEventListener('click', () => {
    if (intervalId) {
        clearInterval(intervalId);
        intervalId = null;
    }
});

createGrid();
