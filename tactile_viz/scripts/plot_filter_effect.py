#!/usr/bin/env python3
"""
Visualize filtering effects on tactile data.

Plots raw vs filtered data for the first 6 points and resultant force.

Usage:
    python3 plot_filter_effect.py <csv_file>
    python3 plot_filter_effect.py  # Use latest file
"""

import sys
import os
import glob
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path


def find_latest_csv(log_dir: str) -> str:
    """Find the most recent filter_demo CSV file."""
    pattern = os.path.join(log_dir, "filter_demo_*.csv")
    files = glob.glob(pattern)
    if not files:
        raise FileNotFoundError(f"No filter_demo CSV files found in {log_dir}")
    return max(files, key=os.path.getmtime)


def load_csv(filepath: str) -> dict:
    """Load CSV without pandas."""
    data = {}
    with open(filepath, 'r') as f:
        header = f.readline().strip().split(',')
        for col in header:
            data[col] = []
        for line in f:
            values = line.strip().split(',')
            for i, col in enumerate(header):
                data[col].append(float(values[i]))
    for col in data:
        data[col] = np.array(data[col])
    return data


def plot_filter_comparison(csv_file: str):
    """Create visualization plots."""
    data = load_csv(csv_file)
    time = data['time']

    # Create 7 subplots: 6 points + resultant
    fig, axes = plt.subplots(4, 2, figsize=(14, 12))
    fig.suptitle('Tactile Filter Effect: Raw vs Filtered (Slope + EMA)', fontsize=14, fontweight='bold')

    colors = {'raw': '#FF6B6B', 'filtered': '#4ECDC4'}

    # Plot first 6 points
    for i in range(6):
        ax = axes[i // 2, i % 2]
        raw_col = f'p{i}_raw_mag'
        filt_col = f'p{i}_filtered_mag'

        ax.plot(time, data[raw_col], color=colors['raw'], alpha=0.6, linewidth=0.8, label='Raw')
        ax.plot(time, data[filt_col], color=colors['filtered'], linewidth=1.2, label='Filtered')
        ax.set_title(f'Point {i}')
        ax.set_xlabel('Time (s)')
        ax.set_ylabel('Force (N)')
        ax.legend(loc='upper right', fontsize=8)
        ax.grid(True, alpha=0.3)

        # Add stats
        raw_std = np.std(data[raw_col])
        filt_std = np.std(data[filt_col])
        reduction = (1 - filt_std / raw_std) * 100 if raw_std > 0 else 0
        ax.text(0.02, 0.98, f'Noise reduction: {reduction:.1f}%',
                transform=ax.transAxes, fontsize=8, verticalalignment='top',
                bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

    # Plot resultant force
    ax = axes[3, 0]
    ax.plot(time, data['resultant_raw_mag'], color=colors['raw'], alpha=0.6, linewidth=0.8, label='Raw')
    ax.plot(time, data['resultant_filtered_mag'], color=colors['filtered'], linewidth=1.2, label='Filtered')
    ax.set_title('Resultant Force')
    ax.set_xlabel('Time (s)')
    ax.set_ylabel('Force (N)')
    ax.legend(loc='upper right', fontsize=8)
    ax.grid(True, alpha=0.3)

    raw_std = np.std(data['resultant_raw_mag'])
    filt_std = np.std(data['resultant_filtered_mag'])
    reduction = (1 - filt_std / raw_std) * 100 if raw_std > 0 else 0
    ax.text(0.02, 0.98, f'Noise reduction: {reduction:.1f}%',
            transform=ax.transAxes, fontsize=8, verticalalignment='top',
            bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

    # Summary stats in last subplot
    ax = axes[3, 1]
    ax.axis('off')

    stats_text = "Filter Performance Summary\n" + "=" * 30 + "\n\n"
    stats_text += f"{'Point':<12} {'Raw Std':>10} {'Filt Std':>10} {'Reduction':>10}\n"
    stats_text += "-" * 44 + "\n"

    for i in range(6):
        raw_std = np.std(data[f'p{i}_raw_mag'])
        filt_std = np.std(data[f'p{i}_filtered_mag'])
        reduction = (1 - filt_std / raw_std) * 100 if raw_std > 0 else 0
        stats_text += f"Point {i:<5} {raw_std:>10.2f} {filt_std:>10.2f} {reduction:>9.1f}%\n"

    raw_std = np.std(data['resultant_raw_mag'])
    filt_std = np.std(data['resultant_filtered_mag'])
    reduction = (1 - filt_std / raw_std) * 100 if raw_std > 0 else 0
    stats_text += f"{'Resultant':<12} {raw_std:>10.2f} {filt_std:>10.2f} {reduction:>9.1f}%\n"

    ax.text(0.1, 0.9, stats_text, transform=ax.transAxes, fontsize=10,
            verticalalignment='top', fontfamily='monospace',
            bbox=dict(boxstyle='round', facecolor='lightgray', alpha=0.8))

    plt.tight_layout()

    # Save
    output_file = csv_file.replace('.csv', '_plot.png')
    plt.savefig(output_file, dpi=150, bbox_inches='tight')
    print(f"Plot saved: {output_file}")

    plt.show()


def main():
    if len(sys.argv) > 1:
        csv_file = sys.argv[1]
    else:
        script_dir = Path(__file__).parent.parent
        log_dir = script_dir / "log"
        try:
            csv_file = find_latest_csv(str(log_dir))
            print(f"Using: {csv_file}")
        except FileNotFoundError as e:
            print(f"Error: {e}")
            sys.exit(1)

    if not os.path.exists(csv_file):
        print(f"Error: File not found: {csv_file}")
        sys.exit(1)

    plot_filter_comparison(csv_file)


if __name__ == "__main__":
    main()
