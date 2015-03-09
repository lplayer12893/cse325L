#include "scheduler.h"
#include "sched_impl.h"

// ****************** THREAD OPERATIONS ****************************************

/**
 * This is a function that will initialize a thread_info_t.
 */
static void init_thread_info(thread_info_t *info, sched_queue_t *queue)
{
	// TODO: Fill this function out
	// Depends on what we put in the thread_info_t structure.
}

/**
 * This is a function that will destroy a thread info.
 * Releases the resources associated with a thread_info_t
 */
static void destroy_thread_info(thread_info_t *info)
{
	// TODO: Fill this function out
	// Depends on what we put in the thread_info_t structure.
}

/**
 * This is a function that will put a thread into the scheduler queue.
 * This should block until the thread can enter the scheduler queue (if the queue is full)
 */
static void enter_sched_queue(thread_info_t *info)
{
	// TODO: Write this function out.
	// Check if the queue has room
	// If it does, add to the queue.
	// If it doesn't, block until we can
}

/**
 * This will be called when the worker has completed. It should remove the thread from the scheduler queue.
 */
static void leave_sched_queue(thread_info_t *info)
{
	// TODO: Write this function out.
	// Remove from the queue
	// Update the queue stats
	// Maybe wake up something that is waiting?
}

/**
 * This is a function that will block until the scheduler allows it to run.
 * While on the scheduler queue, block until thread is scheduled.
 */
static void fifo_wait_for_cpu(thread_info_t * info)
{
	// TODO: Write this function out.
	// Check if the CPU is available.
	// If it is available, return immediately.
	// If it isn't, then block until it is.
}

/**
 * This will be called when the thread is ready to release the CPU
 * Voluntarily relinquish the CPU when this thread's timeslice is over (cooperative multithreading).
 */
static void fifo_release_cpu(thread_info_t * info)
{
	// TODO: Write this function out.
	// Since we are FIFO, I think we just return immediately, and let the process continue.
}

/**
 * This will be called when the thread is ready to pause and wait its next turn.
 * Voluntarily relinquish the CPU when this thread's timeslice is over (cooperative multithreading).
 */
static void rr_release_cpu(thread_info_t * info)
{
	// TODO: Write this function out.
	// Put this in the queue, at the end.
}

/**
 * This should block until its our turn in the queue.
 * While on the scheduler queue, block until thread is scheduled.
 */
static void rr_wait_for_cpu(thread_info_t * info)
{
	// TODO: Write this function out.
	// Block until we are up in the queue.
}

// ******************** SCHEDULER OPERATIONS ***********************************

/**
 * This is a function that will initialize a scheduler queue.
 * Initialize a sched_queue_t
 */
static void init_sched_queue(sched_queue_t *queue, int queue_size)
{
	if (queue == NULL)
	{
		queue = (sched_queue_t *) malloc(sizeof(sched_queue_t));
	}
	queue->q = (list_t *) malloc(sizeof(list_t));
	list_init(queue->q);

	queue->maxSize = queue_size;
	queue->numInQueue = 0;
}

/**
 * This is a function that will destroy a scheduler queue.
 * Release the resources associated with a sched_queue_t
 */
static void destroy_sched_queue(sched_queue_t *queue)
{
	if (queue != NULL)
	{
		// Free the remaining elements in the queue
		list_foreach(queue->q, (void *) free);
		// Free the queue itself
		free(queue->q);
		queue = NULL;
	}

}

/**
 * Allows (signals) a worker thread to execute.
 */
static void wake_up_worker(thread_info_t *info)
{
	// TODO: Write this function out.
}

/**
 * Blocks until the current worker thread relinquishes the CPU.
 */
static void wait_for_worker(sched_queue_t *queue)
{
	// TODO: Write this function out.
}

/**
 * Select the next worker thread to execute. Returns NULL if the scheduler queue is empty.
 */
thread_info_t * next_worker(sched_queue_t *queue)
{
	// TODO: Write this function out.
	return NULL;
}

/**
 * Block until at least one worker thread is in the scheduler queue.
 */
static void wait_for_queue(sched_queue_t *queue)
{
	// TODO: Write this function out.
}

// *************************** END OF FUNCTIONS ********************************

/* These are the functions that will be called when we are using a FIFO scheduling method */
sched_impl_t sched_fifo =
{
	{
		init_thread_info,
		destroy_thread_info,
		enter_sched_queue,
		leave_sched_queue,
		fifo_wait_for_cpu,
		fifo_release_cpu
	},
	{
		init_sched_queue,
		destroy_sched_queue,
		wake_up_worker,
		wait_for_worker,
		next_worker,
		wait_for_queue
	}
};
/* These are the functions that will be called when we are using a round robin scheduling method */
sched_rr =
{
	{
		init_thread_info,
		destroy_thread_info,
		enter_sched_queue,
		leave_sched_queue,
		rr_wait_for_cpu,
		rr_release_cpu
	},
	{
		init_sched_queue,
		destroy_sched_queue,
		wake_up_worker,
		wait_for_worker,
		next_worker,
		wait_for_queue
	}
};