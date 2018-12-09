import express from 'express';
import Controller from '../controllers/Bills';
const router = express.Router();

router.get('/', Controller.getBills);

export default router;