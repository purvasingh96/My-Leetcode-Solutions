class Solution {
  weights: number[]
  constructor(w: number[]) {
    const sum = w.reduce((acc, cur) => acc + cur)

    this.weights = w

    for (let i = 0; i < w.length; i++) {
      const num = w[i]
      this.weights[i] = num / sum
      if (i > 0) this.weights[i] += this.weights[i - 1]
    }
  }

  pickIndex(): number {
    const randomNum = Math.random()
    let left = 0
    let right = this.weights.length - 1
    while (left < right) {
      const mid = Math.floor((left + right) / 2)
      if (randomNum > this.weights[mid]) left = mid + 1
      else right = mid
    }

    return left
  }
}